// Solution in JavaScript

/**
 * @param {number} num
 * @return {number}
 */
var findComplement = function(num) {
    let binary = num.toString(2);
    let length = binary.length;

    let maskedNumber = (1<<length) - 1; 

    return num ^ maskedNumber
};