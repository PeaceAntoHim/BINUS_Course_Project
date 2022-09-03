import React from 'react';

// React Component
function Profile(props) {
    // destructuring
    const {name, hobby} = props
    console.log(props)
    return (
    <div>
        <h3>Hi, nama saya {name}</h3>
        <p>Hobi saya {hobby}</p>
    </div>
  );
}

export default Profile;
