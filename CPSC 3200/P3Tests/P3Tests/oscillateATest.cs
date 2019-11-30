using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace P3Tests
{
     [TestClass]
    public class oscillateATest
    {
        [TestMethod]
        public void advanceyieldTest()
        {

            int[] forbidden = { };
            arithS a = new oscillateA(2, forbidden);
            a.switchAdvance();
            Assert.IsTrue(a.yield() > 0);
            Assert.IsTrue(a.yield() < 0);
            Assert.IsTrue(a.yield() > 0);
            Assert.IsTrue(a.yield() < 0);
            Assert.IsTrue(a.yield() > 0);

        }
        [TestMethod]
        public void retreatyieldTest()
        {

            int[] forbidden = { };
            arithS a = new oscillateA(2, forbidden);
            a.switchRetreat();
            Assert.IsTrue(a.yield() < 0);
            Assert.IsTrue(a.yield() > 0);
            Assert.IsTrue(a.yield() < 0);
            Assert.IsTrue(a.yield() > 0);
            Assert.IsTrue(a.yield() < 0);

        }
        [TestMethod]
        public void resetTest()
        {
            int[] forbidden = { };
            arithS a = new oscillateA(2, forbidden);
            a.switchAdvance();
            Assert.IsTrue(a.yield() > 0);
            Assert.IsTrue(a.yield() < 0);
            a.reset();
            a.switchAdvance();
            Assert.IsTrue(a.yield() > 0);
            Assert.IsTrue(a.yield() < 0);

        }
    }

}
