using System;
namespace P3Tests
{
    public class oscillateA:arithS
    {
        private bool reverseBool;
        public oscillateA(int num,int[] arr) : base(num,arr)
        {
            reverseBool = false;
        }

        public override int yield()
        {
            yieldCount++;
            switch (objState)
            {
               
                case State.Stuck:
                    return thresholdCheck(reverse(current));
                case State.Advance:
                    current += sequence;
                    return thresholdCheck(reverse(current));
                case State.Retreat:
                    current -= sequence;
                    return thresholdCheck(reverse(current));
            }

            return -1; //document this
        }

        private int reverse(int n)
        {
            if (reverseBool)
            {
                reverseBool = false;
                return n * -1;
            }
            else
            {
                reverseBool = true;
                return n;
            }
        }

        public override void reset()
        {
            current = 0;
            objState = State.Stuck;
            yieldCount = 0;
            modechangeCount = 0;
            reverseBool = false;
        }

    }
}
