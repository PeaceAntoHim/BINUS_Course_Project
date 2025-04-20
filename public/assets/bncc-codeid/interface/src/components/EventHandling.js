import React, { useState } from "react";

function EventHandling() {
  const [number, setNumber] = useState(0);

  // arrow function
  const addHandler = () => {
    if (number >= 10) {
      alert("Number max 10");
    } else {
      setNumber(number + 1);
    }
  };

  const subHandler = () => {
    if (number <= 0) {
      alert("Number min 0");
    } else {
      setNumber(number - 1);
    }
  };

  return (
    <div className="container p-3">
      <h1 className="text-primary">{number}</h1>
      <button onClick={addHandler} className="btn btn-sm btn-success me-3">
        + Add
      </button>
      <button onClick={subHandler} className="btn btn-sm btn-danger me-3">
        - Sub
      </button>
    </div>
  );
}

export default EventHandling;
