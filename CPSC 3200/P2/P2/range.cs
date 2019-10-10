/*Author:Lee,Shaun
 * CPSC 3200
 * Version 2.0
 * 
 * Description: takes in 2 factor objects and ping will return true or false depending if the entry is divisible the 2 factor objects
 * 
 * Class Invariant:
 * 1.ping will return a boolean depending if the number is factorable
 * 2.put 2 numbers in the constructor
 * 3.has a bunch of stats methods which returns highest/lowest successful number and number of successes in either int or string
 * 
 * Interface Invariant
 * 1.the entry for ping cannot be a 0 or 1
 * 2.don't put a 0 in the constructor
 * 
 * Implementation Invariant
 * 1.ping returns a boolean
 */
using System;
namespace P2
{
    public class range
    {
        private readonly Factor obj1;
        private readonly Factor obj2;
        private int NumofSuccess;
        private int HighestSuccess;
        private int LowestSuccess;

        String[] array;
        private const uint SIZE = 3;
        public range(int input1, int input2)
        {
            HighestSuccess = 0;
            LowestSuccess = 0;
            NumofSuccess = 0;
            array = new String[SIZE];
            obj1 = new Factor(input1);
            obj2 = new Factor(input2);
        }
        /*
         * Precondition: entry has to be an int that isn't 0 or 1
         * 
         * Postcondition: return a boolean depending if its factorable
         */
        public bool ping(int input)
        {
            if (input == 0 || input == 1)
            {
                throw new System.InvalidOperationException("input cannot be 0 or 1");
            }


            if (obj1.div(input) && obj2.div(input))
            {
                if(HighestSuccess == 0 && LowestSuccess == 0)
                {
                    HighestSuccess = input;
                    LowestSuccess = input;
                }
                if(HighestSuccess < input) HighestSuccess = input;
                if (LowestSuccess > input) LowestSuccess = input;
                NumofSuccess++;
                return true;
            }
           return false;
        }

        public string getStats()
        {
            return "Highest Successful Entry:" + HighestSuccess + " Lowest Sucessful Entry:" + LowestSuccess + " Number of Successes:" + NumofSuccess;
        }

        public int getNumofSuccess()
        {
            return NumofSuccess;
        }

        public int getHighestSuccess()
        {
            return HighestSuccess;
        }

        public int getLowestSuccess()
        {
            return LowestSuccess;
        }

    }
}