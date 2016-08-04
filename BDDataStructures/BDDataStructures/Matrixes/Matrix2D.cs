using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Matrix2D<T>
{
    //We have an arraylist of array lists
    //This list is the rows (y)
    private DLL<DLL<T>> rowList;

    //Size data of the Matrix
    //Number of rows
    private int rowCount;
    //Number of columns
    private int columnCount;
    
    //Constructor needs data of size

    //Constructor with an equal size
    /// <summary>
    /// The constructor for the 2D Matrix.
    /// Remember, this is a static matrix! No resizing it!
    /// </summary>
    /// <param name="_size">The size of the Matrix, in this case it'll be an equal size (_size,_size)</param>
    public Matrix2D(int _size)
    {
        //quick check. If size is 0 or less, make it 1
        if(_size <= 0)
        {
            rowCount = 1;

            columnCount = 1;
        }
        else
        {
            //Row size
            rowCount = _size;

            //Column Size
            columnCount = _size;
        }

        //Create the Matrix
        CreateMatrix();
    }

    //The function to create the matrix
    private void CreateMatrix()
    {
        //Create a new list
        rowList = new DLL<DLL<T>>();

        //create the rows first
        for(int i = 0; i < rowCount; i++)
        {
            DLL<T> nuRow = new DLL<T>();
            //Now, we create the empty spaces for the row (the columns in the current row)
            for(int j = 0; j < columnCount; j++)
            {
                //Create an empty T in each column
                nuRow.Add(default(T));
            }

            //Add the row to our list
            rowList.Add(nuRow);
        }
    }

    //Custom Operator
    public T this[int _x, int _y]
    {
        get
        {
            return GetData(_x, _y);
        }

        set
        {
            SetData(value, _x, _y);
        }
    }

    //protected functions
    
    //Get specified row
    protected DLL<T> GetRow(int _row)
    {
        return rowList[_row];
    }

    protected T GetColumn(DLL<T> _row, int _column)
    {
        return _row[_column];
    }

    //Get data at current location
    protected T GetData(int _x, int _y)
    {
        DLL<T> tRow = rowList[_y];

        //Quick check in case the user got it wrong
        if(tRow != null)
        {
            //If it doesn't exist, it'll return null
            return tRow[_x];
        }

        //In case everything goes to Hell
        return default(T);
    }

    //Set data at current location
    protected bool SetData(T _data, int _x, int _y)
    {
        DLL<T> tRow = rowList[_y];

        //Quick check that the row exists
        if(tRow != null)
        {
            //Set data
            tRow[_x] = _data;
            //Return true
            return true;
        }

        //in case everything went wrong
        return false;
    }

    protected bool ContainsData(T _data)
    {
        //first, make sure data isn't null
        if(_data != null)
        {
            //Search for the data in your row list
        }

        //Return false if we didn't find anything
        return false;
    }

    //Public Functions

    public T GetAt(int _x, int _y)
    {
        int tx = _x;
        int ty = _y;

        if(tx < 0)
        {
            tx = 0;
        }

        if(ty < 0)
        {
            ty = 0;
        }

        return GetData(tx, ty);
    }

    public void RemoveAt(int _x, int _y)
    {
        //Check if the numbers aren't negative
        int tx = _x;
        int ty = _y;
        //is x negative?
        if (tx < 0)
        {
            //Make it 0
            tx = 0;
        }
        //Is y negative?
        if (ty < 0)
        {
            //Make it 0
            ty = 0;
        }

        SetData(default(T), _x, _y);
    }
}
