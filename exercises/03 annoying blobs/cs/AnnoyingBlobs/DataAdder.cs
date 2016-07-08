namespace AnnoyingBlobs
{
    public class DataAdder
    {
        public void DoSomeAdding()
        {
            DataBlob.GetBlob().AddData(newData);
            newData += 10;
        }

        private int newData = 0;
    }
}
