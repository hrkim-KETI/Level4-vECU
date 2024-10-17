//
// Copyright (c) 2010-2024 Antmicro
// Copyright (c) 2011-2015 Realtime Embedded
//
// This file is licensed under the MIT License.
// Full license text is available in 'licenses/MIT.txt'.
//
using System;
using System.Collections.Generic;
using System.Linq;
using Antmicro.Renode.Core;
using Antmicro.Renode.Core.CAN;
using Antmicro.Renode.Exceptions;
using Antmicro.Renode.Logging;
using Antmicro.Renode.Peripherals;
using Antmicro.Renode.Peripherals.CAN;
using Antmicro.Renode.Time;

namespace Antmicro.Renode.Tools.Network
{
    public static class FMICANReceiverExtensions
    {
        public static void CreateFMICANReceiver(this Emulation emulation, string name, bool loopback = false, bool useNetworkByteOrderForLogging = true)
        {
            emulation.ExternalsManager.AddExternal(new FMICANReceiver(loopback, useNetworkByteOrderForLogging), name);
        }
    }

    public sealed class FMICANReceiver : IExternal, IHasOwnLife, IConnectable<ICAN>, INetworkLog<ICAN>
    {
        
        public FMICANReceiver(bool loopback = false, bool useNetworkByteOrderForLogging = true)
        {
            sync = new object();
        
            this.loopback = loopback;
            UseNetworkByteOrderForLogging = useNetworkByteOrderForLogging;

            FMIHandler.OnCANFrameReceived += HandleCANFrameReceived;
            this.Log(LogLevel.Debug, "hrkim-FMICANReceiver is called");
        }

        public void AttachTo(ICAN iface)
        {
            lock(sync)
            {
                if(attached != null)
                {
                    throw new RecoverableException("Cannot attach to the provided CAN periperal as it is already registered in this hub.");
                }
                attached = iface;
            }
        }

        public void DetachFrom(ICAN iface)
        {
            lock(sync)
            {
                if(attached == iface)
                {
                    attached = null;  // 연결 해제
                }
                else
                {
                    this.Log(LogLevel.Warning, "Trying to detach a CAN interface that is not attached.");
                }
            }
        }



        public void Start()
        {
            Resume();
        }

        public void Pause()
        {
            lock(sync)
            {
                started = false;
            }
        }

        public void Resume()
        {
            lock(sync)
            {
                started = true;
            }
        }

        public bool IsPaused => !started;

        public event Action<IExternal, ICAN, ICAN, byte[]> FrameTransmitted;
        public event Action<IExternal, ICAN, byte[]> FrameProcessed;

        public bool UseNetworkByteOrderForLogging { get; set; }


        private void HandleCANFrameReceived(CANMessageFrame frame)
        {
            this.Log(LogLevel.Debug, "hrkim-HandleCANFrameReceived is called");

            lock(sync)
            {
                if(attached != null)
                {
                    this.Log(LogLevel.Debug, $"hrkim-HandleCANFrameReceived: ID = {frame.Id}, Data = {BitConverter.ToString(frame.Data)}");
                    attached.OnFrameReceived(frame);  // 바로 attached에 대해 OnFrameReceived 호출
                }
                else
                {
                    this.Log(LogLevel.Warning, "No attached CAN interface to receive the frame.");
                }
            }
        }


        private  ICAN attached;
        private bool started;
        private readonly object sync;
        private readonly bool loopback;
        // hrkim
        private Queue<CANMessageFrame> messageBuffer;
        private bool bufferFlag;
    }
}

