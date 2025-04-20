import React, { useState } from "react";

function TableProfile() {
  // state
  const [profiles, setProfiles] = useState([
    {
      id: 1,
      name: "Vincent",
      hobby: "makan",
    },
    {
      id: 2,
      name: "Denny",
      hobby: "climbing",
    },
    {
      id: 3,
      name: "Donny",
      hobby: "motoran",
    },
    {
      id: 4,
      name: "tests",
      hobby: "coding",
    },
    {
      id: 5,
      name: "Putri",
      hobby: "jalan2",
    },
  ]);

  const [name, setName] = useState("");
  const [hobby, setHobby] = useState("");

  const submitHandler = (e) => {
    e.preventDefault();
    let lastIndex = profiles.length - 1;
    let id = profiles[lastIndex].id + 1;

    let temp = {
      id,
      name,
      hobby,
    };

    let tempProfiles = [...profiles]
    tempProfiles.push(temp)

    setProfiles(tempProfiles)
  };

  return (
    <div className="container p-3">
      <div className="row">
        <div className="col-8">
          <table className="table table-bordered table-hovered">
            <thead className="table-primary">
              <tr>
                <th>Id</th>
                <th>Name</th>
                <th>Hobby</th>
              </tr>
            </thead>
            <tbody>
              {profiles.map((profile) => {
                const { id, name, hobby } = profile;
                return (
                  <tr key={id}>
                    <td>{id}</td>
                    <td>{name}</td>
                    <td>{hobby}</td>
                  </tr>
                );
              })}
            </tbody>
          </table>
        </div>
        <div className="col-4">
          <div>
            <h3>Add Profile</h3>
            <hr />
          </div>
          <form>
            <div className="mb-3">
              <label className="form-label">Name:</label>
              <input
                onChange={(e) => setName(e.target.value)}
                type="text"
                className="form-control"
                placeholder="Input name..."
              />
            </div>
            <div className="mb-3">
              <label className="form-label">Hobby:</label>
              <input
                onChange={(e) => setHobby(e.target.value)}
                type="text"
                className="form-control"
                placeholder="Input hobby..."
              />
            </div>
            <div className="mb-3">
              <button
                onClick={(e) => submitHandler(e)}
                className="btn btn-sm btn-success"
              >
                SUBMIT
              </button>
            </div>
          </form>
        </div>
      </div>
    </div>
  );
}

export default TableProfile;
