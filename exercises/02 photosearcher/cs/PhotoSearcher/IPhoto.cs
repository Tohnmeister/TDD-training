using System;

namespace PhotoSearcher
{
    public interface IPhoto
    {
        DateTime Date { get; }
        Color Color { get; }
        ContentType ContentType { get; }
    }
}