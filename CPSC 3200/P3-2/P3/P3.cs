using System;
/* Driver Overview:This driver starts off by generating 5 of each type of arithS object. I pass the sequence number and forbidden set
 *                into the arithS,oscillator object. I pass the sequence number,forbidden set and skip number into the skipA obj. I output
 *                the sequence number, forbidden set, and skip number at the top of the driver indexed by the heterogenous collection. Every
 *                Arith Obj starts at 0. sequence number is the incrementor value for the arithS obj.Skip number is the number that makes the
 *                SkipA obj skip an amount of increments.It tests each object by calling yield 7 times while its advance, 7 while its stuck and
 *                7 while its in retreat. it also checks the stats before and after and also after reset. I believe that this will test all the
 *                functionalities of these 3 classes.By default every arithS obj is set to stuck
 */
namespace P3
{
    class MainClass
    {
        static Random random = new Random();

        public static void Main(string[] args)
        {
            // const int SIZE = 15;
            // arithS[] arr = new arithS[SIZE];
            // arr = arithSarrGen();
            // arithSTest(arr);
             
        }
    }
}