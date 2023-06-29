import React from 'react';

interface File {
  name: string;
  size: string;
  dateModified: string;
}

interface DirectoryListingProps {
  files: File[];
}

const DirectoryListing: React.FC<DirectoryListingProps> = ({ files }) => {
  return (
    <div>
      <h1>Index of /public/assets/Algoritma_design_Analysis/</h1>
      <table>
        <thead>
          <tr>
            <th>Name</th>
            <th>Size</th>
            <th>Date Modified</th>
          </tr>
        </thead>
        <tbody>
          {files.map((file) => (
            <tr key={file.name}>
              <td>
                <a href={`/assets/Algoritma_design_Analysis/${file.name}`}>
                  {file.name}
                </a>
              </td>
              <td>{file.size}</td>
              <td>{file.dateModified}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
};

export default DirectoryListing;
