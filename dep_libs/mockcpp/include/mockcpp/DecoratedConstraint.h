/***
   mockcpp is a C/C++ mock framework.
   Copyright [2008] [Darwin Yuan <darwin.yuan@gmail.com>]

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
***/

#ifndef __MOCKCPP_DECORATED_CONSTRAINT_H
#define __MOCKCPP_DECORATED_CONSTRAINT_H

#include <mockcpp/mockcpp.h>
#include <mockcpp/Constraint.h>

MOCKCPP_NS_START


struct DecoratedConstraint : public Constraint
{
    DecoratedConstraint(Constraint* constraint);

    ~DecoratedConstraint();

    bool eval(const RefAny& val) const;
    std::string toString() const;

    virtual bool evalSelf(const RefAny& val) const = 0;
    virtual std::string getName() const = 0;
    virtual std::string getTypeAndValueString() const = 0;

protected:

    bool hasDecoratedConstraint() const;

private:

    std::string getDecoratedConstraintString() const;

private:

    Constraint* decoratedConstraint;
};

MOCKCPP_NS_END

#endif

