//
//  Function.hpp
//
//  Created by Marcus Hall on 9/15/20.
//

#ifndef Function_hpp
#define Function_hpp

template <typename Ret, typename ...Args>
struct Function {
    using FType = Ret(*)(Args...);
    
private:
    bool bInitialized;
    FType Func;
    
public:
    Function() : bInitialized(false), Func(nullptr) {}
    Function(Function& Other) {
        bInitialized = Other.bInitialized;
        Func = Other.Func;
    }
    Function(FType InFunc) {
        bInitialized = (InFunc != nullptr);
        Func = InFunc;
    }
    Function operator=(Function&& Other) {
        this->bInitialized = Other.bInitialized;
        this->Func = Other.Func;
        
        return *this;
    }
    
    Function operator=(FType InFunc) {
        bInitialized = (InFunc != nullptr);
        Func = InFunc;
        
        return *this;
    }
    
    Ret operator()(Args... InArgs) const {
        return Func(InArgs...);
    }
    
    bool IsValid() const {
        return bInitialized;
    }
};


#endif /* Function_hpp */
