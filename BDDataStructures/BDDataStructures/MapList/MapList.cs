using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class MapList<KEY, VALUE>
{

    MapNode<KEY, VALUE> pActiveHead;
    MapNode<KEY, VALUE> pReserveHead;
    MapIterator<KEY, VALUE> pIterator;

    public MapList()
    {
        pActiveHead = null;
        pReserveHead = null;
        pIterator = new MapIterator<KEY, VALUE>();
    }

    public VALUE this[KEY _key]
    {
        get
        {
            return FindData(_key);
        }
    }

    private MapNode<KEY, VALUE> AddActive(MapNode<KEY, VALUE> _node)
    {
        //Check that the key and value aren't null
        if (_node != null)
        {
            //Case 1: the list is Empty
            if (pActiveHead == null)
            {
                pActiveHead = _node;
            }
            //Case 2: The list isn't empty
            else
            {
                //attach the node to the head
                pActiveHead.SetPrev(_node);
                //Attach the node to the head
                _node.SetNext(pActiveHead);
                //Move the Head to the new node
                pActiveHead = _node;
            }
        }

        return _node;
    }

    private MapNode<KEY, VALUE> AddReserve(MapNode<KEY, VALUE> _node)
    {
        if (_node != null)
        {
            //Case 1: the list is Empty
            if (pReserveHead == null)
            {
                pReserveHead = _node;
            }
            //Case 2: The list isn't empty
            else
            {
                //attach the node to the head
                pReserveHead.SetPrev(_node);
                //Attach the node to the head
                _node.SetNext(pReserveHead);
                //Move the Head to the new node
                pReserveHead = _node;
            }
        }

        return _node;
    }

    private MapNode<KEY, VALUE> RemoveActive(MapNode<KEY, VALUE> _node)
    {
        //Is the node not null?
        if (_node != null)
        {
            //We assume the node is in the list
            //Case 1: It's the last node
            if (_node == pActiveHead && pActiveHead.GetNext() == null)
            {
                //Remove the Head
                pActiveHead = null;
            }
            //Case 2: It's the head, but there are more nodes
            else if (_node == pActiveHead)
            {
                //Move head to the next 
                pActiveHead = _node.GetNext();
                //Detach the head 
                pActiveHead.SetPrev(null);
                //Detach the node
                _node.SetNext(null);
            }
            //Case 3: The node is somewhere in the list
            else
            {
                //Detach the next's prev
                if (_node.GetNext() != null)
                {
                    _node.GetNext().SetPrev(_node.GetPrev());
                }

                //Detach the prev's next
                if (_node.GetPrev() != null)
                {
                    _node.GetPrev().SetNext(_node.GetNext());
                }

                //Detach the node
                _node.SetNext(null);
                _node.SetPrev(null);
            }

        }

        return _node;
    }

    private MapNode<KEY, VALUE> PopReserve()
    {
        MapNode<KEY, VALUE> tNode = pReserveHead;

        if (tNode != null)
        {
            //Case 1: There is one node left
            if (tNode.GetNext() == null)
            {
                //The head now points to null
                pReserveHead = null;
            }
            //Case 2: there are more left
            else
            {
                //Move the head
                pReserveHead = tNode.GetNext();
                //Detach the node
                tNode.SetNext(null);
                //Detach the head
                pReserveHead.SetPrev(null);
            }

            return tNode;
        }

        //There is no node, return null
        return null;
    }

    private MapNode<KEY, VALUE> Find(KEY _key)
    {
        pIterator.SetNode(pActiveHead);

        while (pIterator.GetNode() != null)
        {
            if (pIterator.GetNode().GetKey().Equals(_key))
            {
                return pIterator.GetNode();
            }
            //Keep walking Johnny
            pIterator.GoNext();
        }

        return null;
    }

    public bool Contains(KEY _key)
    {
        pIterator.SetNode(pActiveHead);

        while (pIterator.GetNode() != null)
        {
            if (pIterator.GetNode().GetKey().Equals(_key))
            {
                return true;
            }
            //Keep walking Johnny
            pIterator.GoNext();
        }

        return false;
    }

    public VALUE FindData(KEY _key)
    {
        pIterator.SetNode(pActiveHead);

        while (pIterator.GetNode() != null)
        {
            if (pIterator.GetNode().GetKey().Equals(_key))
            {
                return pIterator.GetNode().GetValue();
            }
            //Keep walking Johnny
            pIterator.GoNext();
        }

        return default(VALUE);
    }

    public void Add(KEY _key, VALUE _value)
    {
        if (!Contains(_key))
        {
            MapNode<KEY, VALUE> tNode = PopReserve();

            if (tNode != null)
            {
                tNode.SetKey(_key);
                tNode.SetValue(_value);
            }
            else
            {
                tNode = new MapNode<KEY, VALUE>(_key, _value);
            }
            AddActive(tNode);
        }
    }

    public void Remove(KEY _key)
    {
        if (Contains(_key))
        {
            MapNode<KEY, VALUE> tNode = Find(_key);

            //Remove from active
            RemoveActive(tNode);

            //Add to reserve
            AddReserve(tNode);
        }
    }
}
