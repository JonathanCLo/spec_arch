home:
    ADDL    $zero   5   $1
    ADDL    $zero   5   $2
    ADDL    $5      5   $zero
    ADDL    $1      $2  $3
    STL     $3      $fp 0
    SUBL    $6      $5  $1
    BEQ     $6      @endloop
local:
    ADDL    $zero   $zero   $1
    ADDL    $zero   $zero   $2
    ADDL    $zero   $zero   $3
    JMP     @home
endloop:
    PAL     NOOP
    HALT
