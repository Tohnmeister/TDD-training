using System;

namespace AnnoyingBlobs
{
    public class DataDisplayer
    {
        public void Tick()
        {
            int value = DataBlob.GetBlob().GetDataAtPos(position);
            Console.WriteLine("Data @" + position + "=" + value);
            position++;
        }

        private int position = 0;
    }
}
