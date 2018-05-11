#ifndef PROJECT_NAME_DUMMY_H
#define PROJECT_NAME_DUMMY_H

class ExcitingInterface {
public:
	virtual ~ExcitingInterface() = default;
	virtual void greet() const = 0;
};

class Dummy {
public:
    Dummy(int val);

    int getValue() const;

private:
    int value;



};

#endif //PROJECT_NAME_DUMMY_H
