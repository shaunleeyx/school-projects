/**Author:Shaun Lee
 *Class Overview: This class is a member of arithS class except it skips yield() calls depending on what is the skip number
 *Class Invariant: Constructor 1st and 2nd arg is the same as arithS.
 *                 3rd arg takes in an int
 *                 Obj is set to stuck mode by default
 *                 Obj sequence starts out at 0
 *Interface Invariant: Constructor takes in 3 arg in param 1.) int that is the sequence number
 *                                                         2.) int[] that will be the forbidden set
 *                                                         3.) int that will be the skip number
 *                     Yield works the same way as arithS except yield will skip the number of yields depending on the skip number
 *                     reset() restarts all field to intial state except the skipnum                
 *                                                         
 **/
namespace P6 {
    public class skipA : arithS, iskipA {
        private int skipNum;
        //PRECONDITION: positive num, int[] of any number, positive number
        //POSTCONDITION: sets num to sequence, arr to forbidden and num2 to skipNum
        public skipA (int difference, int[] fset, int thold, int skipn) : base (difference, fset, thold) {
            if (skipn < 0) skipn *= -1;
            skipNum = skipn + 1;
        }
        //PRECONDITION:
        //POSTCONDITION:
        public override int yield () {
            for (int i = 0; i < skipNum - 1; i++) {
                base.yield ();
            }
            return base.yield ();
        }

        public override int numGen () {
            return yieldCount / skipNum;

        }
    }
}
/*
 * Implementation invariant: Skipnum takes in the first arg of the constructor. It skips the n amount of yield calls depending on the skipnum
 *                           if skipnum is intialized to a negative number it is intialized to absolute value of the number
 *                           yield skips sequences iteratively depending on skipNum
 *                           if obj's state is in neither 3 states then it returns -1
 *                           skipA's yield function skips the base yield function
 *                           Did not override the reset function because all the data members that it uses belongs to arithS so there is not point. I shouldn't reset the skipNum value because the value is encapsulated via constructor.
 *                           numgen for skipA will return the number of yields for a skipA obj more accurately
 *                           
 */