/* Author:Shaun Lee
 * April 30,019
 * Version 1
 * 
 *  Class Invariant: it return true if the entry's pth char is a number and also contains mixed characters and a $ sign
 * 
 *  Interface Invariant: no null characters
 * 
 * Implementation invariant: none
 * 
 */
using System;
using System.Linq;

public class excessC: pwdCheck
{
    public excessC(int input): base(input)
    {
        active = true;
        p = input;
     }
    //PRE: no null characters are legal
    //POST: returns true if the string has a integer at pth index of string, Mixedcases, and contains '$'
    public override bool request(string password)
    {
        if (active)
        {
            //Any makes it so it tests for the entire string and Contains checks to see if the string contains the $ character
            if (Char.IsDigit(password[p-1]) && password.Any(char.IsUpper) && password.Any(char.IsLower) && password.Contains('$'))
            {
                Console.WriteLine("asdasd");
                return true;
            }
            return false;
        }
        else
        {
            return false;
        }
    }

}

