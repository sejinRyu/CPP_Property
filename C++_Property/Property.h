#pragma once
//
//template <typename Type,typename ObjectClass>
//class Property
//{
//private:
//	using GetFunction = const Type(ObjectClass::*)() const;
//	using SetFunction = void(ObjectClass::*)(const Type);
//	//typedef Type(ObjectClass::*GetFunction)()const;
//	//typedef void(ObjectClass::*SetFunction)(Type);
//
//	ObjectClass& Instance;
//	GetFunction _Get;
//	SetFunction _Set;
//
//public:
//	Property(ObjectClass& instance,
//		GetFunction get,
//		SetFunction set)
//		:Instance(instance), _Get(get), _Set(set)
//	{
//
//	}
//
//	const Type Get() const
//	{
//		return (Instance.*_Get)();
//	}
//	void Set(const Type value)
//	{
//		(Instance.*_Set)(value);
//	}
//
//	/*operator const Type() const
//	{
//		return (Instance.*_Get)();
//	}
//	void operator=(const Type value)
//	{
//		(Instance.*_Set)(value);
//	}*/
//};

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
		MoveFunction move)
		:Instance(instance), _Get(get), _Copy(copy), _Move(move)
	{

	}

	const Type Get() const
	{
		return (Instance.*_Get)();
	}
	void Copy(const Type& value)
	{
		(Instance.*_Copy)(value);
	}
	void Move(Type&& value)
	{
		(Instance.*_Move)(static_cast<Type&&>(value));
	}

	operator const Type() const
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
	}
};