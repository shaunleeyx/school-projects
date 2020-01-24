using System;

/* Author:Shaun Lee
 * April 30,019
 * Version 1
  * 
  * Class Invariant: constructor sets str 
  *                  
  *            
 *  Interface Invariant: no negative numbers in flipFunc
 * 
 * Implementation invariant: if you put a integer too high it sets it to the string length
 *                           
 *                           
 * 
 */

public class Flip: iFlip
{
    string str;

    //PRE:input string
    //POST:sets str to input 

    public Flip(string input)
    {
        str = input;
    }

    //PRE:input integer
    //POST:returns pw reversed at the length of int

    public string flipFunc(int input)
    {
        if (input > str.Length) input = str.Length;
        char[] temp = str.ToCharArray();
        char ctemp;
        for(int i = 0; i < input/2; i++)
        {
            ctemp = temp[i];
            temp[i] = temp[input - i - 1];
            temp[input - i - 1] = ctemp;
        }
        string result = new string(temp);
        return result;
    }


}

