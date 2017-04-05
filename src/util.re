/* string -> float */
let toFloat str => float_of_string str;

/* float -> string */
let toString flt => {
  let str = string_of_float flt;

  Js.String.endsWith "." str
    ? Js.String.replace "." "" str
    : str;
};

/* string -> bool */
let strEmpty str => String.length str == 0;
