#ifndef SBFELEMSTIFFMATRIXHEXA20_H
#define SBFELEMSTIFFMATRIXHEXA20_H

#include "sbfDeclspec.h"
#include "sbfEnums.h"

class sbfPropertiesSet;
class sbfElement;

/*
 *      7------18-------6
 *     /|              /|
 *    19              17|
 *   /  |            /  |
 *  4-------16------5   |
 *  |   |           |   |
 *  |   15          |   14  ^ Z
 *  |   |           |   |   |
 *  |               |   |   |
 *  12  |           13  |   |    / Y
 *  |   3 - - -10 - |- -2   |   /
 *  |  /            |  /    |  /
 *  | 11            | 9     | /
 *  |/              |/      |/
 *  0-------8-------1       0-----------> X
*/

class DECLSPEC sbfElemStiffMatrixHexa20
{
public:
    sbfElemStiffMatrixHexa20();
};

#endif // SBFELEMSTIFFMATRIXHEXA20_H
