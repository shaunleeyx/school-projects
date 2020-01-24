/* Author:Shaun Lee
 * April 30,019
 * Version 1
  * 
  * Class Invariant: password checker that returns true if its a legal password and if it doesn't have any forbidden characters
  *                  password length has to be greater than p 
 * 
 *  Interface Invariant: no null characters
 * 
 * Implementation invariant: constructor intializes the p value and also made a getActive for the client
 * changed it so p has to be equal or greater than 2
 * 
  */

using System;

public class pwdCheck:ipwdCheck
{
    protected bool active;
    protected int p;
    protected uint count;

    public pwdCheck(int p)
    {
        active = true;
        if (p >= 2)
        {
            this.p = p;
        }
        else
        {
            p = 2;
        }

    }
        //PRE: any string without a null character
        //POST: returns true if the string doesn't have any forbidden char and pw's length is greater than p
    public virtual bool request(string password)
    {
        count++;
        if(count % p == 0)
        {
            if(active){active = false;}
            else {active = true;}
        }

        char[] charpw = password.ToCharArray();
        if (active)
        {
            if(password.Length < p)
            {
                return false;
            }

            foreach (char ch in charpw)
            {
                if(System.Convert.ToInt32(ch) < 33 || System.Convert.ToInt32(ch) > 126)
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }

}