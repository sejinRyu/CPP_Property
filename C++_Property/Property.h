#pragma once

template <typename Type, typename ObjectClass>
class Property
{
private:
	using GetFunction = const Type(ObjectClass::*)() const;
	using CopyFunction = void(ObjectClass::*)(const Type&);
	using MoveFunction = void(ObjectClass::*)(Type&&);

	ObjectClass& Instance;
	GetFunction _Get;
	CopyFunction _Copy;
	MoveFunction _Move;

public:
	Property(ObjectClass& instance,
		GetFunction get,
		CopyFunction copy,
		MoveFunction move = nullptr)
		:Instance(instance), _Get(get), _Copy(copy), _Move(move)
	{

	}

	const Type Get() const
	{
		return (Instance.*_Get)();
	}
	/*void Copy(const Type& value)
	{
		(Instance.*_Copy)(value);
	}
	void Move(Type&& value)
	{
		(Instance.*_Move)(static_cast<Type&&>(value));
	}*/
	void Set(const Type& value)
	{
		(Instance.*_Copy)(value);
	}
	void Set(Type&& value)
	{
		if(_Move==nullptr)
			(Instance.*_Copy)(value);
		else (Instance.*_Move)(static_cast<Type&&>(value));
	}

	/*operator const Type() const
	{
		return Get();
	}
	void operator=(const Type& value)
	{
		Copy(value);
	}
	void operator=(Type&& value)
	{
		Move(static_cast<Type&&>(value));
	}*/
};