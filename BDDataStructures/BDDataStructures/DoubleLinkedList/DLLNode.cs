using System;

public class DLLNode<T>
{
    //Our links to our neighbour nodes
    private DLLNode<T> pNext;
    private DLLNode<T> pPrev;

    //The data we are to hold
    private T pData;

    //Simple constructor
    public DLLNode()
    {
        //Set the neighbour links to null
        pNext = null;
        pPrev = null;
        //Data is null
        pData = default(T);
    }
    public DLLNode(T _data)
    {
        //Set the neighbour links to null
        pNext = null;
        pPrev = null;
        //Set data to the given one
        pData = _data;
    }


    //The pNext functions
    public void SetNext(DLLNode<T> _next)
    {
        pNext = _next;
    }
    public DLLNode<T> GetNext()
    {
        return pNext;
    }

    //The pPrev functions
    public void SetPrev(DLLNode<T> _prev)
    {
        pPrev = _prev;
    }
    public DLLNode<T> GetPrev()
    {
        return pPrev;
    }

    //Data functions
    public void SetData(T _data)
    {
        pData = _data;
    }
    public T GetData()
    {
        return pData;
    }
}
