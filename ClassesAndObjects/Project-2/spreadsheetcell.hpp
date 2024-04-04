
//-------------- Access Control ------------------------------
class SpreadsheetCell
{
    void setValue(double inValue); // now has private access
public:
    double getValue() const;

private:
    double mValue;
};

struct SpreadsheetCell
{
    void setValue(double inValue);
    double getValue() const;

private:
    double mValue;
};

struct Point
{
    double x;
    double y;
};

//-------------------------- Order of Declarations --------------------------
class SpreadsheetCell
{
public:
    void setValue(double inValue);

private:
    double mValue;

public:
    double getValue() const;
};

//-------------------- In-Class Member Initializers -------------------------
class SpreadsheetCell
{

private:
    double mValue = 0;
};