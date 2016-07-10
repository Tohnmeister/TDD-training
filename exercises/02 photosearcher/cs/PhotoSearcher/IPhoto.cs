using System;

namespace PhotoSearcher
{
    public interface IPhoto
    {
        int Id { get; }
        DateTime Date { get; }
        Color Color { get; }
        ContentType ContentType { get; }
    }
}