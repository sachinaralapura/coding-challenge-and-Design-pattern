#include <iostream>
#include <stack>
using namespace std;

// ---------------------- abstract memento ----------------------
class Memento
{
public:
    virtual void setText(string) = 0;
    virtual string getText() const = 0;
};

// ---------------------- concrete memento ----------------------

class TextAreaMemento : public Memento
{
private:
    string text;

public:
    TextAreaMemento() {}
    TextAreaMemento(string text) : text(text) {}
    void setText(string text)
    {
        this->text = text;
    };
    string getText() const override
    {
        return this->text;
    };
};

// ---------------------- originator ----------------------

class TextArea
{

private:
    string text;

public:
    TextArea() {};
    void setText(string text) { this->text = text; }
    string getText() { return this->text; }
    Memento *takeSnapShot()
    {
        return new TextAreaMemento(this->text);
    }

    void restore(Memento *meme)
    {
        this->text = meme->getText();
    }
    friend ostream &operator<<(ostream &out, TextArea &);
    friend ostream &operator<<(ostream &out, TextArea *);
};

ostream &operator<<(ostream &out, TextArea &txt)
{
    out << txt.getText();
    return out;
}

ostream &operator<<(ostream &out, TextArea *txt)
{
    out << txt->getText();
    return out;
}

// ---------------------- caretaker ----------------------

class Editor
{
private:
    TextArea *textarea;
    stack<Memento *> *history;

public:
    Editor()
    {
        this->textarea = new TextArea();
        this->history = new stack<Memento *>();
    }

    void write(string text)
    {
        this->textarea->setText(text);
        this->history->push(this->textarea->takeSnapShot());
    }

    void undo()
    {
        if (!this->history->empty())
        {
            this->textarea->restore(this->history->top());
            this->history->pop();
        }
    }
    void display()
    {
        cout << this->textarea << endl;
    }
};

// ---------------------- main ----------------------

int main(int argc, char const *argv[])
{
    Editor *editor = new Editor();
    editor->write("Sachin is dilusional");
    editor->write("sachin is not dilusional");
    editor->undo();
    editor->display();
    editor->undo();
    editor->display();
    return 0;
}
