using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AnnoyingBlobs
{
    [TestClass]
    public class DataAdderTest
    {
        [TestInitialize]
        public void SetUp()
        {
        }

        [TestCleanup]
        public void TearDown()
        {
        }

        [TestMethod]
        public void TestData()
        {
            var myDataAdder = new DataAdder();
            myDataAdder.DoSomeAdding();
        }
    }
}
