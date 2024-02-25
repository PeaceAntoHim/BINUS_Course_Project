import Link from "next/link";
import styles from "./page.module.css";

export default function Home() {
  return (
    <main className={styles.main}>
      <h1>Algorithm Repositories</h1>
      <ul>
        <li>
          <Link href="assets/">All Course Computer Science</Link>
        </li>
        <li>
          <Link href="assets/Algoritma_design_Analysis">
            Artificial_Intelligence
          </Link>{" "}
          - Created 10 months ago
        </li>
        <li>
          <a href="assets/Banker_Algorithms/">Banker_Algorithms</a> - Added 8
          months ago
        </li>
        <li>
          <a href="assets/Physics_and_Biology/">
            Computational Physics and Biology
          </a>{" "}
          - Updated new course 3 weeks ago
        </li>
        <li>
          <a href="assets/Data_Structure/">Data_Structure</a> - Updated new
          learn last month
        </li>
        <li>
          <a href="assets/GOLANG/">GOLANG</a> - Created new 6 months ago
        </li>
        <li>
          <a href="assets/Latiahn_VIcon/">Latiahn_VIcon</a> - Added new last
          year
        </li>
        <li>
          <a href="assets/Latihan_Number_operation/">
            Latihan_Number_operation
          </a>{" "}
          - Created new last year
        </li>
        <li>
          <a href="assets/Latihan_String_operation/">
            Latihan_String_operation
          </a>{" "}
          - Created new last year
        </li>
        <li>
          <a href="assets/Latihan_vicon2/">Latihan_vicon2</a> - Created new last
          year
        </li>
        <li>
          <a href="assets/Scientific_Computing/">Scientific_Computing</a> -
          Added new example last month
        </li>
        <li>
          <a href="assets/Thread/">Thread</a> - Created thread 9 months ago
        </li>
        <li>
          <a href="assets/Tugas_1/">Tugas_1</a> - Perbaiki lagi last year
        </li>
        <li>
          <a href="assets/Tugas_Bitwise/">Tugas_Bitwise</a> - Added new last
          year
        </li>
        <li>
          <a href="assets/Tugas_Forum/">Tugas_Forum</a> - Learned selection sort
          and implemented the algorithm last year
        </li>
        <li>
          <a href="assets/Tugas_Kelompok_2/">Tugas_Kelompok_2</a> - Vicon 2 last
          year
        </li>
        <li>
          <a href="assets/Tugas_Kelompok_3/">Tugas_Kelompok_3</a> - Added new
          last year
        </li>
        <li>
          <a href="assets/Tugas_Kelompok_4/">Tugas_Kelompok_4</a> - Finished my
          team project last year
        </li>
        <li>
          <a href="assets/Tugas_Personal_2/">Tugas_Personal_2</a> - Added new
          last year
        </li>
        <li>
          <a href="assets/Tugas_kelompok_1/">Tugas_kelompok_1</a> - Buat tugas 2
          kelompok last year
        </li>
        <li>
          <a href="assets/Vicon_5/">Vicon_5</a> - Made new program at Vicon last
          year
        </li>
        <li>
          <a href="assets/Vicon_Terakhir/">Vicon_Terakhir</a> - Learned how to
          manipulate strings last year
        </li>
        <li>
          <a href="assets/bncc-codeid/">bncc-codeid</a> - Updated new 10 months
          ago
        </li>
      </ul>
    </main>
  );
}
