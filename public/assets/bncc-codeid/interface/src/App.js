import React from "react";
import "bootstrap/dist/css/bootstrap.css";
import "./App.css";

import TableProfile from "./components/TableProfile";

// React Component
function App() {
  // JSX => Syntactical Sugar utk HTML tp sebenarnya adalah bahasa JS
  return (
    <div className="App">
      <div className="container p-3 text-center bg-dark">
        <h1 className="text-white">Front End Development with React.js</h1>
      </div>

      <TableProfile></TableProfile>
    </div>
  );
}

export default App;
