//Shaun Lee
//CPSC 3200
//Version 5.0

using System;
public class Factor
{
    //declare fields
    private int factor;
    private bool active;
    private int count;
    private int lastnum;
    //intialize fields
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
    //resets factor's field to intial state
    public void reset()
    {
        active = true;
        count = 0;
    }
    //returns true if the entry is divisible by factor
    public bool div(int input)
    {
        if(!active)
        {
            //As a design choice it throws an exception if active is false
            throw new System.InvalidOperationException("inactive");
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
    public int getFactor()
    {
        return factor;
    }
    public int divCount()
    {
        return count;
    }
}

