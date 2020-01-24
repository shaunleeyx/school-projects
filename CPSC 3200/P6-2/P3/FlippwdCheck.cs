using System;
/* Author:Shaun Lee
 * April 30,019
 * Version 1
  * 
  * Class Invariant: I made the default pw "eclipse123" which can be overwritten later
  *                  request function returns bool if input matches pw
  *                  seperated pwdcheck,excessC,compundC's request functions unique to function name 
  *                  
  *            
 *  Interface Invariant: no nulls or negatives for p value
 * 
 * Implementation invariant: i set the default value of k for compundC to be 2
 *                           i made request into a unique function that returns a bool if it guesses the pw
 *                           
 *                           
 * 
 */
public class FlippwdCheck:iFlip,ipwdCheck,iexcessC,icompundC
{
    private readonly string defaultpw = "hello world";
    private string pw;
    private readonly int defaultK = 2;
    private Flip flipobj;
    private pwdCheck pwdcheckobj;
    private excessC excessCobj;
    private compundC compundCobj;

    //PRE:input integer
    //POST:P value set to integer

    public FlippwdCheck(int input)
    {
        pw = defaultpw;
        flipobj = new Flip(pw);
        pwdcheckobj = new pwdCheck(input);
        compundCobj = new compundC(input, defaultK);
        excessCobj = new excessC(input);
    }

    //PRE:input string
    //POST:returns bool if the input is equal to pw

    public bool request(string input)
    {
        return (input == pw);
    }

    //PRE:input string
    //POST:set pw to string

    public bool changepw(string input)
    {
        if (input.Length > 1)
        {
            pw = input;
            return true;
        }
        else
        {
            return false;
        }
    }

    //PRE:NONE
    //POST:returns bool based on pwdCheck request function

    public bool pwdCheckrequest()
    {
        return pwdcheckobj.request(pw);
    }

    //PRE:NONE
    //POST:returns bool based on excessC request function

    public bool excessCrequest()
    {
        return excessCobj.request(pw);
    }

    //PRE:input integer
    //POST:returns pw reversed at the length of int

    public string flipFunc(int input)
    {
        flipobj = new Flip(pw);
        return flipobj.flipFunc(input);
    }


    //PRE:NONE
    //POST:returns bool based on excessC request function

    public bool compundCrequest()
    {
        return compundCobj.request(pw);
    }

}

