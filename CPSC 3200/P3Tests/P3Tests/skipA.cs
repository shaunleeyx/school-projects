using System;
namespace P3Tests
{
    public class skipA:arithS
    {
        private int skipNum;
        public skipA(int num, int[] arr,int num2) : base(num, arr)
        {
            skipNum = num2+1;
        }

        public override int yield()
        {
            yieldCount++;
            switch (objState)
            {
                case State.Stuck:
                    return thresholdCheck(current);
                case State.Advance:
                    for(int i = 0; i < skipNum; i++)
                    {
                        current += sequence;
                    }
                    return thresholdCheck(current);
                case State.Retreat:
                    for (int i = 0; i < skipNum; i++)
                    {
                        current -= sequence;
                    }
                    return thresholdCheck(current);
            }

            return -1; //document this
        }
    }
}
