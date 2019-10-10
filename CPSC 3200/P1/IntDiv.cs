/**
 *Class Overview: This class gets the remainder of two numbers with some rules explained in the invariances
 *Class Invariant:active is true and perm is false when intialized by constructor.active changes when test returns the same number twice. perm changes to false when reset() is invoked when active is true
 *Interface Invariant:div number is positive. negative div and 0 numbers default to 1 so no divide by 0. When active is false it disables the functionality of test(). This can be fixed by reset(). However if perm is active it is permanently disabled
 **/
using System;
namespace Project1
{
	public class intDiv
	{
		private uint div;
		private bool active;
        private bool perm;
        private int lastnum;

        //PRECONDITION:input any number
        //POSTCONDITION: it sets div to num and intializes all other fields to a value or a state
        public intDiv(int num)
		{
            if (num <= 0) num = 1;
			active = true;
            perm = false;
            div = (uint)num;
            lastnum = -1;
		}
        //PRECONDITION:input a positive number 
        //POSTCONDITION:returns the remainder of the number you inputted divided by div or -1 or -2 depending on the state of active and perm
        public int test(uint num)
		{
            if (lastnum == num % div)
            {
                active = false;
            }
            if (perm)
            {
                return -2;
            }
            if (active)
            {
                lastnum = (int)(num % div);
                return (int)lastnum;
            }
            else
            {
                return -1;
            }
           
		}
        //PRECONDITION:active can be true or false
        //POSTCONDITION: if active is false then it is reinitialized to true and if active is true then permanent is true
        public void reset()
        {
            if (active)
            {
                perm = true;
            }
            else
            {
                active = true;
                lastnum = -1;
            }

        }
        //PRECONDITION:none
        //POSTCONDITION:returns active's state
        public Boolean getActive()
        {
            if (active == true) return true;
            else return false; 
        }
        //PRECONDITION:none
        //POSTCONDITION:returns perm's state
        public Boolean getPerm()
        {
            if (perm == true) return true;
            else return false;
        }
    }

}

//Implementation invariant:test() returns -1 when active is false and -2 when perm inactive is true. negative div and 0 numbers default to 1. i set lastnum to -1 because lastnum can only be positive it doesn't overlap incase the first number the client test() is the lastnum
