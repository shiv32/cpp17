class SpreadsheetCell
{
    void setValue(double inValue); // now has private access
public:
    double getValue() const;

private:
    double mValue;
};
//----------------------------------------------------
class SpreadsheetCell
{
public:
    void setValue(double inValue);

private:
    double mValue;

public:
    double getValue() const;
};
//--------------------------------------------------
struct SpreadsheetCell
{
    void setValue(double inValue);
    double getValue() const;

private:
    double mValue;
};
//--------------------------------------------------
struct Point
{
    double x;
    double y;
};