//
// Copyright (c) 2010-2020 Antmicro
// Copyright (c) 2011-2015 Realtime Embedded
//
// This file is licensed under the MIT License.
// Full license text is available in 'licenses/MIT.txt'.
//
using System;
using Antmicro.Renode.Core;
using Antmicro.Renode.Logging;
using Antmicro.Migrant;

namespace Antmicro.Renode.Peripherals.Miscellaneous
{
    public class LED : IGPIOReceiver, ILed
    {
        public LED(bool invert = false)
        {
            inverted = invert;
            state = invert;
            sync = new object();
        }

        public void OnGPIO(int number, bool value)
        {
            if(number != 0)
            {
                throw new ArgumentOutOfRangeException();
            }

            State = inverted ? !value : value;
        }

        public void Reset()
        {
            state = inverted;
        }

        [field: Transient]
        public event Action<ILed, bool> StateChanged;

        public bool State 
        { 
            get => state;

            private set
            {
                lock(sync)
                {
                    if(value == state)
                    {
                        return;
                    }

                    state = value;
                    StateChanged?.Invoke(this, state);
                    //this.Log(LogLevel.Noisy, "LED state changed to {0}", state);
                    // this.Log(LogLevel.Info, "LED state changed to {0}", state);
                    // 현재 Renode 가상 실행 시간(ElapsedVirtualTime) 가져오기
                    var currentTime = this.GetMachine().ElapsedVirtualTime;

                    // LED 상태 변경 로그 출력 (시간 포함)
                    this.Log(LogLevel.Error, "LED state changed to {0} at virtual time {1}", state, currentTime);
                }
            }
        }
        // hrkim : add for robot test
        public bool ReadState()
        {
            return state;
        }

        private bool state;

        private readonly bool inverted;
        private readonly object sync;
    }
}

