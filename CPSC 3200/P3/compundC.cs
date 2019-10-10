/* Author:Shaun Lee
 * April 30,019
 * Version 1
 * 
 * Class Invariant: 1.its the same thing as pwdCheck but it return true when there is a repeating letter 
 *                  2.the number of cycles is above k then it will always return false
 * 
 * Interface Invariant: don't use null character
 * 
 * Implementation invariant: I made the creation of k in the constructor
 */
using System;

public class compundC : pwdCheck
{
    private int k;
    private int cycle;

    public compundC(int input, int k): base(input)
    {
        active = true;
        this.k = k;
        p = input;
        cycle = 0;
    }
    //PRE: don't put null character
    //POST:returns true if the string doesn't have any forbidden char and also if there is less cycles than k and password length has to be greater than p
    public override bool request(string password)
    {

        int temp = ' ';
        count++;
        if (count % p == 0)
        {
            if (active) { active = false; }
            else { active = true; cycle++; }

        }

        char[] charpw = password.ToCharArray();
        if (active && (cycle <= k))
        {
            if (password.Length < p)
            {
                return false;
            }

            foreach (char ch in charpw)
            {

                foreach (char fch in forbidden)
                {
                    if (ch == fch)
                    {
                        return false;
                    }
                }
            }

            foreach (char ch in charpw)
            {
 
                if(ch == temp)
                {
                    return true;
                }
                temp = ch;
            }
            return false;
        
        }
        else
        {
            return false;
        }
    }
}

