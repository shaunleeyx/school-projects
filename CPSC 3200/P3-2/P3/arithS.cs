/**Author:Shaun Lee
 *Class Overview: The purpose of this class is to function like an arithmetic sequence
 *Class Invariant:  Constuctor 1st argument can take only positive numbers
 *                  forbidden list can be any number that doesn't overflow an int
 *                  yield() behaves differently depending on what state the obj is in
 *                  numGen() returns depending on how many times yield is called
 *                  getmodechangeCount() returns depending on how many times you state switched
 *                  if yield's return is in the forbidden set then yield's return will be the last number that wasn't in the forbidden set and before threshold
 *                  There are accessors to get information about arithS
 *                  Obj is defaulted to stuck mode
 *                  
 *Interface Invariant:  current always starts out at 0
     *                  threshold is at 5. so forbidden will happen after 5 numbers have been generated.
     *                  Constructor takes in a 2 arg in param. 1st arg = sequence number which increments your return value for yield.
     *                                                         2nd arg = a int array you pass in and when the amount of calls you made exceeds the threshold(5) then you cannot return numbers in the forbidden set
     *                  arithS has three states. Stuck,Advance,Retreat
     *                  Stuck - when yield() is called return will never increment.
     *                  Advance - when yield() is called return will increment by sequence int
     *                  You can switch to these three states by using switchAdvance(),switchStuck(),switchRetreat()
     *                  reset() - resets this obj to its intial state with the same sequence and forbidden
     *                  numGen() - returns the number of generated numbers called from yield()
 **/

using System;
namespace P3
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
        private int lastnum;

        protected enum State
        {
            Advance,
            Stuck,
            Retreat
        }
        //PRECONDITION: 1st arg:postive number,2nd arg:an int array with any number
        //POSTCONDITION:sequence = 1st arg, forbidden = 2nd arg
        public arithS(int difference,int[] fset, int thold)
        {
            if( difference < 0)  difference= 0;
            current = 0; 
            threshold = thold-1; 
            forbidden = fset;
            sequence = difference; // add or sub num to current
            objState = State.Stuck;
            yieldCount = 0;
            modechangeCount = 0;
        }
        //PRECONDITION:none
        //POSTCONDITION:switches state to advance if its not in advance
        public void switchAdvance()
        {
            if(objState != State.Advance)
            {
                objState = State.Advance;
                modechangeCount++; 
            }
        }
        //PRECONDITION:none
        //POSTCONDITION:switches state to stuck if its not in stuck
        public void switchStuck()
        {
            if(objState != State.Stuck)
            { 
                objState = State.Stuck;
                modechangeCount++;
            }
        }
        //PRECONDITION:none 
        //POSTCONDITION:switches state to retreat if its not in retreat.
        public void switchRetreat()
        {
            if(objState != State.Retreat)
            { 
                objState = State.Retreat;
                modechangeCount++;
            }
        }
        //PRECONDITION:obj has to be in one of the 3 states
        //POSTCONDITION: returns a number depending on what state the obj was on
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
            return -1; 
        }

        public virtual int numGen()
        {
            return yieldCount;
        }
        //PRECONDITION:altered obj
        //POSTCONDITION:turns the obj back to default
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
        //PRECONDITION: a int
        //POSTCONDITION:if number is in forbidden set then return lastnum but if not then return the number passed in
        protected int forbiddenCheck(int num)
        {
            if (inForbidden(num))
            {
                return lastnum;
            }
            else
            {
                lastnum = num;
                return num;
            }
        }
        //PRECONDITION: a int
        //POSTCONDITION: checks to see if number is in forbidden set
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
        //PRECONDITION: a int  
        //POSTCONDITION: returns int normally if below or at threshold else its going to go through forbidden check
        protected int thresholdCheck(int num)
        {
            if(yieldCount > threshold+1)
            {
                return forbiddenCheck(num);
            }
            else
            {
                lastnum = num;
                return num;
            }
            
        }
    }
}
/*
 *
 * Implementation invariant: current is intialized at 0
 *                           threshold intialized at 5
 *                           if num is negative then its intialized to 0
 *                           lastnum is the last number before yield is in forbidden set
 *                           tresholdCheck(int) checks if the amount of yield calls exceed threshold
 *                           inForbidden(int) checks if yield's return is in the forbidden set
 *                           forbiddenCheck(int) decides what to do with the number if its in forbiddenset
 *                           obj's state is intialized to stuck by default
 *                           if obj is in neither of the 3 states yield will return -1
 *                           I set the starting value to 0 since 0 isn't a error code
 *                          made numgen a virtual function because its different for skipA
 */
                            
