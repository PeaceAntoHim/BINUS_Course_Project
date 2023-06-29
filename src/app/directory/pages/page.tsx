import React from 'react';
import { GetServerSideProps, NextPage } from 'next';
import DirectoryListing from '../components/DirectoryListing';

interface File {
  name: string;
  size: string;
  dateModified: string;
}

interface IndexPageProps {
  files: File[];
}

const IndexPage: NextPage<IndexPageProps> = ({ files }) => {
  return <DirectoryListing files={files} />;
};

export const getServerSideProps: GetServerSideProps<IndexPageProps> = async () => {
  const response = await fetch('/api/directory');
  const files: File[] = await response.json();

  return {
    props: {
      files,
    },
  };
};

export default IndexPage;
