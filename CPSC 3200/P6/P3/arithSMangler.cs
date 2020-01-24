/**Author:Shaun Lee
 *Class Overview: 
 * This class does every function of parent and derived classes of mangler and arithS
 * 
 *Class Invariant: 
 * if you insert a number in arithSnum or manglerNum that is not between 0 and 2 it will default to an arithS obj
 *reset() will reset the arithS obj and mangler obj to its original state in the arithMangler class
 * skipn and clear will have default values which you can change later
 * default state of arithS is stuck
 * if arithSnum is 0 then its a arithS, 1 will be a oscillateA, 2 will be a skipA
 * 
 *  
 *Interface Invariant: 
 * skipnum will default to 1 
 * clear will default to 1
 * thold will default to 0 if less than 0
  **/
namespace P6 {
    public class arithSMangler : iarithS, imangler {
        private arithS arithObj;
        private mangler manglerObj;
        private int[] fset;
        private int skipn;
        private int clear;
        private int diff;
        private int thold;
        private int x;

        public arithSMangler (int arithSnum, int manglerNum, int diff, int thold, int x) {
            fset = new int[]{};
            skipn = 1;
            clear = 1;
            this.diff = diff;
            this.thold = thold;
            this.x = x;
            if (arithSnum == 0) arithObj = new arithS(diff,fset,thold);
            else if (arithSnum == 1) arithObj = new oscillateA(diff,fset,thold);
            else if (arithSnum == 2) arithObj = new skipA(diff,fset,thold,skipn);
            else arithObj = new arithS(diff,fset,thold);

            if(manglerNum == 0) manglerObj = new mangler(x);
            else if (manglerNum == 1)  manglerObj = new amplifier(x);
            else if (manglerNum == 2) manglerObj = new puzzler(x,clear);
            else manglerObj = new mangler(x);
        }

        /**
         * Precondition:int
         * Postcondition: reintializes arithObj as a skip obj with a new skip 
         **/
        public void changeSkip(int skip){
            skipn = skip;
            if(arithObj is skipA) arithObj = new skipA(diff,fset,thold,skipn);
        }
        /**
         * Precondition: int 
         * Postcondition: reintializes arithObj as a puzzlerobj with new clear
         **/
        public void changeClear(int c){
            clear = c;
            if(manglerObj is puzzler) manglerObj = new puzzler(x,c);
        }
        /**
         * Precondition: int array
         * Postcondition: reintializes obj with a new fset 
         **/
        public void changeFset(int[] arr){
            fset = arr;
            if(arithObj .GetType() ==  typeof(arithS)) arithObj = new arithS(diff,fset,thold);
            if(arithObj.GetType() ==  typeof( oscillateA)) arithObj = new oscillateA(diff,fset,thold);
            if(arithObj.GetType() ==  typeof(skipA)) arithObj = new skipA(diff,fset,thold,skipn);
            arithObj.switchAdvance();
        }
        /**
         * Precondition:none
         * Postcondition:switches arithS state to advance
         **/
        public void switchAdvance () {
            arithObj.switchAdvance ();
        }

        /**
         * Precondition:none 
         * Postcondition:switches arithS state to stuck
         **/
        public void switchStuck () {
            arithObj.switchStuck ();
        }
        /**
         * Precondition:none
         * Postcondition: switches arithS to retreat
         **/
        public void switchRetreat () {
            arithObj.switchRetreat ();
        }
        /**
         * Precondition:a arithS obj
         * Postcondition:returns an int
         **/
        public int yield () {
            return arithObj.yield ();
        }
        /**
         * Precondition:none 
         * Postcondition:returns number of yields
         **/
        public int numGen() {
            return arithObj.numGen();
        }

        /**
         * Precondition:arithS and mangler
         * Postcondition: resets the entire obj
         **/
        public void reset () {
            arithObj.reset ();
            manglerObj.reset ();
        }
        /**
         * Precondition:none
         * Postcondition: returns change count
         **/
        public int getmodechangeCount () {
            return arithObj.getmodechangeCount ();
        } 
        /**
         * Precondition:mangler obj
         * Postcondition:returns an int from request function from mangler
         **/
        public int request (int b) {
            return manglerObj.request (b);
        }
        /**
         * Precondition:none
         * Postcondition:returns number from mangler obj
         **/
        public int getNum () {
            return manglerObj.getNum ();
        }
    }
}

/**
 * Implementation Invariant: 
 * 1st arg of the constructor sets arithObj to a ArithS,oscillateA,SkipA obj depending on the int from 0-2
 * if the 1st argument is not from 0-2 it will default to an ArithS obj
 * 2nd arg of the constructor sets manglerObj to a mangler,amplifier,puzzler obj depending on the int from 0-2
 * if the 2nd argument is not from 0-2 it will default to a mangler obj
 * uses the yield function from the arithS class depending on the arithS type
 * uses the request function from the mangler class depending on the mangler type
 * use changeSkip to change the skipnum value
 * switchAdvance,switchStuck,switchRetreat switches the state of the arithSobj
 * getmodechangecount() returns the number of times you change the state of the arithS obj
 * numGen() returns the yieldCount of arithS
 * reset() resets both manglerObj and arithSobj
 * clear will be set to default of 1 and can be change by clearChange
 * fset will be set to a default of an empty set and can be changed by changeFset
 * changing clear,skip,fset reintializes the obj
 */