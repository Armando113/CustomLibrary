using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class MapNode<KEY, VALUE>
{
    //Variables
    MapNode<KEY, VALUE> pNext;
    MapNode<KEY, VALUE> pPrev;

    KEY key;
    VALUE value;

    public MapNode(KEY _key, VALUE _value)
    {
        key = _key;
        value = _value;
    }

    public void SetNext(MapNode<KEY, VALUE> _next)
    {
        pNext = _next;
    }
    public MapNode<KEY, VALUE> GetNext()
    {
        return pNext;
    }

    public void SetPrev(MapNode<KEY, VALUE> _prev)
    {
        pPrev = _prev;
    }
    public MapNode<KEY, VALUE> GetPrev()
    {
        return pPrev;
    }

    public void SetKey(KEY _key)
    {
        key = _key;
    }
    public KEY GetKey()
    {
        return key;
    }

    public void SetValue(VALUE _value)
    {
        value = _value;
    }
    public VALUE GetValue()
    {
        return value;
    }

}
