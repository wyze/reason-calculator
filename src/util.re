/* string -> bool */
let strEmpty str => String.length str == 0;

/* string -> float */
let toFloat str => strEmpty str ? 0.0 : float_of_string str;

/* float -> string */
let toString flt => {
  let str = string_of_float flt;

  Js.String.endsWith "." str
    ? Js.String.replace "." "" str
    : str;
};

/* string -> bool */
let isFloat str => Js.String.includes "." str;
