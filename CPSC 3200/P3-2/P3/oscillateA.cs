/**Author:Shaun Lee
 *Class Overview: This class is a member of arithS. It has exactly the same functionality except the yield return values switch between positive and negative
 *Class Invariant:  inherits public functionality of arithS
 *                  oscillates's yield is exacly the same as arithS except the return value oscillates between positive and negative
 *                  this obj is intialized to start out at 0
 *                  Obj is set to stuck mode by default
 *Interface Invariant: oscillates constructor: 1st arg - takes in a number greater than or equal to 0
 *                                             2nd arg - takes a int array sets it as forbidden set
 *                                             yield returns values oscillating between positive and negative
 *                                             numGen() returns depending on how many times yield is called
 *                                             getmodechangeCount() returns depending on how many times you state switched
 *                                             if yield's return is in the forbidden set then yield's return will be the last number that wasn't in the forbidden set and before threshold
 *                                             There are accessors to get information about arithS
 *                                             reset() resets all fields to initial state except forbidden set and sequence
 **/
using System;
namespace P3
{
    public class oscillateA:arithS
    {   //PRECONDITION:and int and an int arr
        //POSTCONDITION: encapsulates both of those numbers to sequence and forbidden set
        private bool reversebool;
        public oscillateA(int difference,int[] fset,int thold) : base(difference,fset,thold)
        {
            reversebool = false;
        }
        //PRECONDITION: obj should be set in 1 of the three states
        //POSTCONDITION: returns values incremented by sequence
        public override int yield()
        {
            return thresholdCheck(reverse(base.yield()));
        }
        public override void reset()
        {
            base.reset();
            reversebool = false;
        }
        //precondition: takes in an int
        //postcondition: returns a negative and positive int you passed in. in sequence
        private int reverse(int n)
        {
            if (reversebool)
            {
                reversebool = false;
                return n * -1;
            }
            else
            {
                reversebool = true;
                return n;
            }
        }

    }
}
/*
 * implementation invariant:
 * function: reverse(int): sets the return value of the number to negative for every other number. it does this by multiplying the number by -1 every other call
 *           reset(): resets the reversebool to false that originally have been set to false;
 *           yield(): it first reverses current and then checks if its exceed the threshold and its in the forbidden set
 *           if yield is called and the obj is in none of the 3 states then it returns -1
 *           reversebool is to keep track of the oscillating
 *           obj starts out at 0
 *           changed the override yield function. made the oscillatea yield use the base yield function and then modify and return the value. 
 *           
 */
