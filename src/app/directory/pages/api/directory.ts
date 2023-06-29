import { NextApiRequest, NextApiResponse } from "next";
import fs from "fs";
import path from "path";

interface File {
  name: string;
  size: string;
  dateModified: string;
}

export default function handler(
  req: NextApiRequest,
  res: NextApiResponse<File[]>
) {
  const directoryPath = path.join(
    process.cwd(),
    "/public/assets/Algoritma_design_Analysis"
  );
  const files = fs.readdirSync(directoryPath);

  const fileData = files.map((file) => {
    const filePath = path.join(directoryPath, file);
    const stats = fs.statSync(filePath);
    return {
      name: file,
      size: stats.isFile() ? `${stats.size} B` : "",
      dateModified: stats.mtime.toDateString(),
    };
  });

  res.status(200).json(fileData);
}
