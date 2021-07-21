namespace HyperNovaLabs.Api.Extensions
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Threading.Tasks;

    public static class CommonExtensions
    {
        public static void Add<T>(this ICollection<T> Source, IEnumerable<T> Values)
        {
            foreach (var Value in Values)
            {
                Source.Add(Value);
            }
        }

        public static IEnumerable<T> RemoveIQueryable<T>(this IEnumerable<T> Source)
        {
            foreach (var Value in Source)
            {
                yield return Value;
            }
        }
    }
}
