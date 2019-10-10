using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Project1
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod()]
        public void Test_remainder_should_be_0_ReturnsTrue()
        {
            intDiv a = new intDiv(2);
            int remainder = a.test(6);
            Assert.AreEqual(remainder, 0);
        }

        [TestMethod()]
        public void Active_should_be_true()
        {
            intDiv a = new intDiv(2);
            a.test(6);
            Assert.AreEqual(a.getActive(), true);
        }

        [TestMethod()]
        public void Same_remainder_twice_active_IsFalse()
        {
            intDiv a = new intDiv(2);
            a.test(6);
            a.test(6);
            Assert.AreEqual(a.getActive(), false);
        }

        [TestMethod()]
        public void Reset_Active_Back_ToTrue()
        {
            intDiv a = new intDiv(2);
            a.test(6);
            a.test(6);
            a.reset();
            Assert.AreEqual(a.getActive(), true);
        }

        [TestMethod()]
        public void Permanent_Inactive_isTrue()
        {
            intDiv a = new intDiv(2);
            a.test(6);
            a.reset();
            Assert.AreEqual(a.getPerm(), true);
        }

    }
}
