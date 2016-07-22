using System;

public class DLLIterator<T>
{
    DLLNode<T> myNode;

    public DLLIterator()
    {

    }

    //Set the starting Node
    public void SetStartNode(DLLNode<T> _node)
    {
        myNode = _node;
    }

    //Walk to the next node, if available
    public void GoNext()
    {
        if (myNode != null)
        {
            myNode = myNode.GetNext();
        }
    }

    //Walk to the previous node if available
    public void GoPrev()
    {
        if (myNode != null)
        {
            myNode = myNode.GetPrev();
        }
    }

    //Get the node you are currently in
    public DLLNode<T> GetNode()
    {
        return myNode;
    }
}