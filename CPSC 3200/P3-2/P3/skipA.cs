/**Author:Shaun Lee
 *Class Overview: This class is a member of arithS class except it skips yield() calls depending on what is the skip number
 *Class Invariant: Constructor 1st and 2nd arg is the same as arithS.
 *                 3rd arg takes in an int
 *                 Obj is set to stuck mode by default
 *                 Obj sequence starts out at 0
 *Interface Invariant: Constructor takes in 3 arg in param 1.) int that is the sequence number
 *                                                         2.) int[] that will be the forbidden set
 *                                                         3.) int that will be the skip number
 *                     Yield works the same way as arithS except yield will skip the number of yields depending on the skip number
 *                     reset() restarts all field to intial state except the skipnum                
 *                                                         
 **/
using System;
namespace P3
{
    public class skipA:arithS
    {
        private int skipNum;
        //PRECONDITION: positive num, int[] of any number, positive number
        //POSTCONDITION: sets num to sequence, arr to forbidden and num2 to skipNum
        public skipA(int num, int[] arr,int num2) : base(num, arr)
        {
            if(num2 < 0) num2 = 0;
            skipNum = num2+1;
        }
        //PRECONDITION:
        //POSTCONDITION:
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

            return -1;
        }



    }
}
/*
 * Implementation invariant: Skipnum takes in the first arg of the constructor. It skips the n amount of yield calls depending on the skipnum
 *                           if skipnum is intialized to a negative number it is intialized to 0
 *                           yield skips sequences iteratively depending on skipNum
 *                           if obj's state is in neither 3 states then it returns -1
 *
 */
