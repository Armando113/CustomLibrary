using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Matrix2DNode<T>
{
    //The node for the 2D Matrix

    //Instead of having next or prev, the node has x & y coordinate values
    //Don't worry about neighbours, the Matrix itself will deal with that!
    private int x;
    private int y;

    //The data the node will hold
    private T pData;

    //Constructor requires an initial x & y value
    public Matrix2DNode(int _x, int _y)
    {

    }
}
