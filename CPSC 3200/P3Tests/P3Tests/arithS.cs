using System;
namespace P3Tests
{
    public class arithS
    {
        protected int current;
        protected int sequence;
        protected State objState;
        private readonly int threshold;
        protected static int[] forbidden;
        protected int modechangeCount;
        protected int yieldCount;
        private int remember;//doc

        protected enum State
        {
            Advance,
            Stuck,
            Retreat
        }
        
        public arithS(int num,int[] arr)
        {
            current = 0; //document this 
            threshold = 5; //document this
            forbidden = arr;
            sequence = num; // add or sub num to current
            objState = State.Stuck;
            yieldCount = 0;
            modechangeCount = 0;
        }

        public void switchAdvance()
        {
            objState = State.Advance;
            modechangeCount++;
        }

        public void switchStuck()
        {
            objState = State.Stuck;
            modechangeCount++;
        }
        
        public void switchRetreat()
        {
            objState = State.Retreat;
            modechangeCount++;
        }

        public virtual int yield()
        {
            yieldCount++;
            switch (objState)
            {
                case State.Stuck:
                    return thresholdCheck(current);
                case State.Advance:
                    current += sequence;
                    return thresholdCheck(current);
                case State.Retreat:
                    current -= sequence;
                    return thresholdCheck(current);
            }
            return -1; //document this
        }

        public int numGen()
        {
            return yieldCount;
        }

        public virtual void reset()
        {
            current = 0;
            objState = State.Stuck;
            yieldCount = 0;
            modechangeCount = 0;
        }

        public int getmodechangeCount()
        {
            return modechangeCount;
        }

        protected int forbiddenCheck(int num)
        {
            if (inForbidden(num))
            {
                return remember;
            }
            else
            {
                remember = num;
                return num;
            }
        }

        protected bool inForbidden(int n)
        {
            for (int i = 0; i < forbidden.Length; i++)
            {
                if (forbidden[i] == n)
                {
                    return true;
                }
            }
            return false;
        }

        protected int thresholdCheck(int num)
        {
            if(yieldCount > threshold+1)
            {
                return forbiddenCheck(num);
            }
            else
            {
                remember = num;
                return num;
            }
            
        }
    }
}
