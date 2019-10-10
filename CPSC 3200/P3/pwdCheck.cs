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
  */

using System;

public class pwdCheck
{
    protected bool active;
    protected int p;
    protected uint count;
    protected char[] forbidden = new char[] { ' ', '', '⇔', '£','¥','€','©','®','™','†','‡','§','¶','°','·','…','–','—','±','×','÷','¼','⅓','½','⅔','¾','μ','π','←','↑','→','↓','↔','↵','⇐','⇑','⇒','⇓','⇔','♠','♣','♥','♦'}; //common non-ascii chars
    public pwdCheck(int p)
    {
        active = true;
        this.p = p;

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
                foreach(char fch in forbidden)
                {
                    if(ch == fch)
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
        //PRE: none
        //POST: returns active bool
    public bool getActive()
    {
        return active;
    }
}