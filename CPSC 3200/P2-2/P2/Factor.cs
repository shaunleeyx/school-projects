/*Author:Lee,Shaun
 * CPSC 3200
 * Version 2.0
 * 
 * Description:takes a integer and div will return true or false depending on its entry. Also it becomes inactive which means it will always return false until you reset it
 * 
 * Class Invariant:
 * 1.if you div the same number twice it will trigger it to be inactive which will always return false until you reset it
 * 2.reset() will reset the factor class to intial state
 * 3.
 * 
 * Interface Invariant
 * 1.cannot use 0 as input for div
 * 
 * Implementation Invariant
 * 1.changed the exception for inactive to just return false. 
 * 2.added an exception if input is 0 it should tell the user to not use 0 as the input
 * 3.removed getFactor() since dingle told me to
 */
using System;
public class Factor
{
    private int factor;
    private bool active;
    private int count;
    private int lastnum;

    public Factor(int input)
    {
        factor = input;
        active = true;
        count = 0;
    }
    public bool isActive()
    {
        return active;
    }
    /*
     * Precondition:intial fields have to be changed
     *    
     *Postcondition:changes fields to intial state
     */    
    public void reset()
    {
        active = true;
        count = 0;
    }
    /*
    * Precondition: Has to be a value greater than 0
    *    
    *Postcondition: returns a boolean depending if the value is factorable by the dividend
    */
    public bool div(int input)
    {
        //i made this design choice in P2. Client shouldn't beable to divide by zero
        if(input == 0)
        {
           throw new System.InvalidOperationException("input cannot be 0");
        }
        if(!active)
        {
            //As a design choice it throws an exception if active is false
            return false;
        }

        if (input == lastnum && count > 0)
        {
            active = false;
        }

        if (input % factor == 0)
        {
            if (active)
            {
                count++;
            }

            lastnum = input;
            return true;
        }

        lastnum = input;
        return false;
    }

    public int divCount()
    {
        return count;
    }
}

