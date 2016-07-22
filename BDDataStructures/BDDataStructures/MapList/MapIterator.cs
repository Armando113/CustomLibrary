using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class MapIterator<KEY, VALUE>
{
    MapNode<KEY, VALUE> myNode;

    public MapIterator()
    {
        myNode = null;
    }

    public void SetNode(MapNode<KEY, VALUE> _node)
    {
        myNode = _node;
    }

    public void GoNext()
    {
        if (myNode != null)
        {
            myNode = myNode.GetNext();
        }
    }

    public void GoPrev()
    {
        if (myNode != null)
        {
            myNode = myNode.GetPrev();
        }
    }

    public MapNode<KEY, VALUE> GetNode()
    {
        return myNode;
    }

}
